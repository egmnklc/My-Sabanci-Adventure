%{
#define INITIAL_SIZE 10
#ifdef YYDEBUG
yydebug = 1;
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "egemenkilic-hw3.h"
void yyerror (const char *msg) /* Called by yyparse on error */ {return; }

// Function Headers
int checkIdentifier(Scope *scope, ExprNode *expr);
void addExpressionToList(Scope *scope, ExprNode *newExpr);

void setIdent (IdentNode * ident1, StringNode * str1);
void sendMail (ExprNode * expr1, RecipientList *recipientList, char *currentSenderEmail);
void initGlobalScope();
void enterScope();
void exitScope();
void validateDateTime(char* date, char* time, int lineNum);

bool isValidDate(char* date);
bool isValidTime(char* time);

ExprNode * makeExpressionNodeFromString(StringNode str);
ExprNode * makeExpressionNodeFromIdent(IdentNode ident);

RecipientNode* createRecipientNode(IdentNode ident, char* email);
RecipientNode* createRecipientNodeFromString(char* name, char* email);
RecipientList* createRecipientList(RecipientNode* firstNode);
RecipientList* addRecipientToList(RecipientNode* newNode, RecipientList* list);

ScheduledEmail* createScheduledEmail(char *date, char *time, char *senderEmail, char *recipientInfo, char *message);
void addScheduledEmailToList(ScheduledEmail *newEmail);

Scope *globalScope = NULL;
Scope *currentScope = NULL;

// Dynamic array to keep track of errors
ExprNode ** expressions;
int expressionsSize = 100;
int exprIndex = 0;

// This is a flag indicating there is a semantic error in the program 
int error = 0;

char ** errors;
char* currentSenderEmail = NULL;
char* globalMessage = NULL;
char* globalTo = NULL;
char* scheduleDate = NULL;
char* scheduleTime = NULL;
char* globalName = NULL;

char* userecipientMailInfo = NULL;
char* userecipientMailName = NULL;

int errorSize = 100;
int errorIndex = 0;

ScheduledEmail *scheduledEmailsHead = NULL;

%}

%union{
    IdentNode identNode;
    StringNode stringNode;
    ExprNode *exprNodePtr;
    ScheduledEmail * scheduledEmailPtr;
    int lineNum;

    RecipientNode *recipientNode;
    RecipientList *recipientList;
    
}

%token <identNode> tIDENT
%token <stringNode> tSTRING
%token <stringNode> tADDRESS tDATE tTIME


%token tMAIL tENDMAIL tSCHEDULE tENDSCHEDULE tSEND tTO tFROM tSET tCOMMA tCOLON tLPR tRPR tLBR tRBR tAT
%start program

/* type keyword is used for non-terminals */
%type <exprNodePtr> option
%type <recipientList> recipientList
%type <recipientNode> recipient
%%


program : statements
;

statements : 
            | setStatement statements
            | mailBlock statements
;

mailBlock : tMAIL tFROM tADDRESS tCOLON { 
    enterScope(); 
    currentSenderEmail = strdup($3.value); 
    globalTo = currentSenderEmail;

    }
    statementList tENDMAIL {
    exitScope();
    free(currentSenderEmail); // Free the sender's email after use
    currentSenderEmail = NULL;
    globalTo = NULL;
}


statementList : 
                | setStatement statementList
                | sendStatement statementList
                | scheduleStatement statementList
;

sendStatements : sendStatement
                | sendStatement sendStatements 
;

sendStatement : tSEND tLBR option tRBR tTO tLBR recipientList tRBR {
                // printf("sendStatement: option value: %s\n", $3->stringValue);
                RecipientNode *current = $7->head;
                userecipientMailInfo = current->email;
                userecipientMailName = current->name;
                // printf("sendStatement: Current sender name: %s\n\n", userecipientMailName);
                // printf("sendStatement: Email scheduled to be sent from %s\n to", currentSenderEmail);
                if (!error && userecipientMailName && scheduleDate && scheduleTime){
                    char* formattedMessage = (globalMessage != NULL) ? globalMessage : "(No message)";
                    // printf("Expected: E-mail scheduled to be sent from %s on %s, %s to %s: %s\n", globalTo, scheduleDate, scheduleTime, userecipientMailName, formattedMessage);
                }
                sendMail($3, $7, currentSenderEmail); // $3 is the message and $7 is the recipientList
                //7 DE EKLENMELI
}
;

option: tSTRING{
        $$ = makeExpressionNodeFromString($1);

}  
        | tIDENT{
        $$ = makeExpressionNodeFromIdent($1);
}
;


recipientList : recipient {
            $$ = createRecipientList($1);
            }
            | recipient tCOMMA recipientList {
                $$ = addRecipientToList($1, $3);
            }
;

recipient : tLPR tADDRESS tRPR {
            $$ = createRecipientNodeFromString(NULL, $2.value); // Assuming $2 is email of type char*
          }
          | tLPR tSTRING tCOMMA tADDRESS tRPR {
            $$ = createRecipientNodeFromString($2.value, $4.value); // $2 is name (stringNode), $4 is email (char*)
          }
          | tLPR tIDENT tCOMMA tADDRESS tRPR {
            $$ = createRecipientNode($2, $4.value); // $2 is identifier (IdentNode), $4 is email (char*)
          }
;

scheduleStatement : tSCHEDULE tAT tLBR tDATE tCOMMA tTIME tRBR tCOLON {
                        validateDateTime($4.value, $6.value, $4.lineNum);

                        scheduleDate = $4.value;
                        // printf("scheduleStatement: scheduleDate: %s\n", scheduleDate);
                        scheduleTime = $6.value;
                        // printf("scheduleStatement: scheduleTime: %s\n", scheduleTime);
                        // printf("scheduleStatement: userecipientMailInfo %s\n", userecipientMailInfo);
                        // printf("scheduleStatement: userecipientMailName %s\n", userecipientMailName);
                        

       
                        // printf("scheduleStatement: Sender mail address: %s\n", globalTo);
                        // printf("scheduleStatement: userecipientMailName: %s\n", userecipientMailName);
                        // printf("scheduleStatement: GlobalName: %s\n\n", globalName);
                        // printf("scheduleStatement: globalMessage: %s\n", globalMessage);
                        if (!error && userecipientMailName){
                                char* formattedMessage = (globalMessage != NULL) ? globalMessage : "(No message)";
                                printf("E-mail scheduled to be sent from %s on %s, %s to %s: %s\n", globalTo, scheduleDate, scheduleTime, userecipientMailName, formattedMessage);
                        }
                        // ScheduledEmail* createScheduledEmail(char *date, char *time, char *senderEmail, char *recipientInfo, char *message);
                        if (userecipientMailInfo){
                            ScheduledEmail *newEmail = createScheduledEmail(scheduleDate, scheduleTime, globalTo, userecipientMailName, globalMessage);
                            addScheduledEmailToList(newEmail);
                        }
                        // addScheduledEmailToList(newEmail);
                        
                        // printf("Date Value %s\n", $4.value);
                        // printf("Time Value %s\n", $4.value);
                        // printf("Date Line num %d\n", $4.value);
                    } sendStatements tENDSCHEDULE
;

setStatement : tSET tIDENT tLPR tSTRING tRPR {
                // Same thing as assign
                setIdent(&$2, &$4);
                }
;
%%

ScheduledEmail* createScheduledEmail(char *date, char *time, char *senderEmail, char *recipientInfo, char *message) {
    ScheduledEmail *newEmail = malloc(sizeof(ScheduledEmail));
    if (newEmail == NULL) {
        fprintf(stderr, "Memory allocation failed for ScheduledEmail\n");
        exit(EXIT_FAILURE);
    }

    // Initialize fields of newEmail
    newEmail->date = strdup(date);
    /* printf("createScheduledEmail: newEmail->date: %s", newEmail->date); */
    newEmail->time = strdup(time);
    /* printf("createScheduledEmail: newEmail->time: %s", newEmail->time); */
    newEmail->senderEmail = strdup(senderEmail);
    /* printf("createScheduledEmail: newEmail->senderEmail: %s", newEmail->senderEmail); */
    newEmail->recipientInfo = strdup(recipientInfo); // Set recipientInfo
    /* printf("createScheduledEmail: recipientInfo: %s", recipientInfo); */
    newEmail->message = strdup(message); // Set message
    /* printf("createScheduledEmail: newEmail->message: %s", newEmail->message); */
    newEmail->next = NULL;
    return newEmail;
}
// Helper function to compare dates in "dd/mm/yyyy" format
int compareDates(const char* date1, const char* date2) {
    int day1, month1, year1, day2, month2, year2;
    sscanf(date1, "%d/%d/%d", &day1, &month1, &year1);
    sscanf(date2, "%d/%d/%d", &day2, &month2, &year2);

    if (year1 != year2) return year1 - year2;
    if (month1 != month2) return month1 - month2;
    return day1 - day2;
}

// Helper function to compare times in "hh:mm" format
int compareTimes(const char* time1, const char* time2) {
    int hour1, minute1, hour2, minute2;
    sscanf(time1, "%d:%d", &hour1, &minute1);
    sscanf(time2, "%d:%d", &hour2, &minute2);

    if (hour1 != hour2) return hour1 - hour2;
    return minute1 - minute2;
}

void addScheduledEmailToList(ScheduledEmail *newEmail) {
    if (newEmail == NULL) return;

    newEmail->next = scheduledEmailsHead;
    scheduledEmailsHead = newEmail;
}

void addScheduledEmail(char *date, char *time, char *senderEmail, char *recipientInfo, char *message, int lineNum) {
    ScheduledEmail *newEmail = (ScheduledEmail *)malloc(sizeof(ScheduledEmail));
    newEmail->date = strdup(date);
    newEmail->time = strdup(time);
    newEmail->senderEmail = strdup(senderEmail);
    newEmail->recipientInfo = strdup(recipientInfo);
    newEmail->message = strdup(message);
    newEmail->lineNum = lineNum;
    newEmail->next = NULL;

    // Add to the head of the list or another strategy as preferred
    newEmail->next = scheduledEmailsHead;
    scheduledEmailsHead = newEmail;
}

// Sorting function
void sortScheduledEmails() {
    /* printf("Inside sortScheduledEmails\n"); */
    bool swapped;
    ScheduledEmail *current;
    ScheduledEmail *lastPtr = NULL;

    if (scheduledEmailsHead == NULL)
        return;

    do {
        swapped = false;
        current = scheduledEmailsHead;

        while (current->next != lastPtr) {
            int dateComparison = compareDates(current->date, current->next->date);
            /* printf("sortScheduledEmails dateComparison: %s", dateComparison); */
            int timeComparison = compareTimes(current->time, current->next->time);
            /* printf("sortScheduledEmails timeComparison: %s", timeComparison); */

            if (dateComparison > 0 || (dateComparison == 0 && (timeComparison > 0 || (timeComparison == 0 && current->lineNum > current->next->lineNum)))) {
                // Swap current and current->next
                ScheduledEmail *temp = current->next;
                current->next = temp->next;
                temp->next = current;
                if (current == scheduledEmailsHead) {
                    scheduledEmailsHead = temp;
                }
                swapped = true;
            }
            current = current->next;
        }
        lastPtr = current;
    } while (swapped);
}

// Helper function to convert a month number to its name
const char* getMonthName(int month) {
    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    if (month >= 1 && month <= 12) {
        return months[month - 1];
    }
    return "";
}

// Function to format date from "dd/mm/yyyy" to "Month Day, Year"
char* formatDate(const char* date) {
    int day, month, year;
    sscanf(date, "%d/%d/%d", &day, &month, &year);

    const char* monthName = getMonthName(month);
    char* formattedDate = (char*)malloc(30 * sizeof(char)); // Allocate enough space

    if (formattedDate != NULL) {
        sprintf(formattedDate, "%s %d, %d", monthName, day, year);
    }

    return formattedDate; // Remember to free this memory after use!
}

void printScheduledEmails() {
    sortScheduledEmails();
    ScheduledEmail *current = scheduledEmailsHead;
    while (current != NULL) {
        char* formattedDate = formatDate(current->date);
        printf("E-mail scheduled to be sent from %s on %s, %s to %s: %s\n",
               current->senderEmail, formattedDate, current->time, current->recipientInfo, current->message);
        free(formattedDate); // Free the formatted date string after use
        current = current->next;
    }
}

bool isValidDate(char* date) {
    int day, month, year;

    if (sscanf(date, "%d/%d/%d", &day, &month, &year) != 3) return false; // Incorrect format
    if (day < 1 || day > 31) return false;
    if (month < 1 || month > 12) return false;
    /* if (year < 1900 || year > 2100) return false; // Adjust year range as needed */

    // Check for leap year if needed

    return true;
}

bool isValidTime(char* time) {
    int hour, minute;

    if (sscanf(time, "%d:%d", &hour, &minute) != 2) return false; // Incorrect format
    if (hour < 0 || hour > 23) return false;
    if (minute < 0 || minute > 59) return false;

    return true;
}

Scope* createNewScope(Scope *parent) {
    Scope *newScope = malloc(sizeof(Scope));
    newScope->variables = malloc(sizeof(ExprNode*) * INITIAL_SIZE); // Define INITIAL_SIZE
    newScope->varCount = 0;
    newScope->varSize = INITIAL_SIZE;
    newScope->parent = parent;
    return newScope;
}

void validateDateTime(char* date, char* time, int lineNum) {
    if (!isValidDate(date)) {
        error = 1;
        printf("ERROR at line %d: date object is not correct (%s)\n", lineNum, date);
    }
    if (!isValidTime(time)) {
        error = 1;
        printf("ERROR at line %d: time object is not correct (%s)\n", lineNum, time);
    }
}

void enterScope() {
    Scope *newScope = createNewScope(currentScope);
    currentScope = newScope;
}

void exitScope() {
    if (currentScope->parent != NULL) {
        Scope *temp = currentScope;
        currentScope = currentScope->parent;
        free(temp); // Also, free the variables and the list itself
    }
}

void initGlobalScope() {
    globalScope = createNewScope(NULL); // NULL as it has no parent
    currentScope = globalScope;
}

int checkIdentifier(Scope *scope, ExprNode *expr) {
    /* printf("checkIdentifier: Checking for identifier '%s'\n", expr->value); */
    if (expr->value == NULL) {
        return -1; // Indicates the expression is a string.
    }

    // Start checking from the current scope and move up to parent scopes.
    while (scope != NULL) {
        /* printf("checkIdentifier: Checking scope with %d variables\n", scope->varCount); */
        /* int i;
        for (i = 0; i < scope->varCount; i++) {
            if (scope->variables[i] != NULL && strcmp(expr->value, scope->variables[i]->value) == 0) {
                printf("checkIdentifier: Found '%s' in current scope at index %d\n", expr->value, i);
                // Identifier found in the current scope.
                return i;
            }
        } */
        // Move to the parent scope if the identifier is not found in the current scope.
        scope = scope->parent;
        /* printf("checkIdentifier: Moving to parent scope\n"); */
    }

    // Identifier not found in any scope.
    /* printf("checkIdentifier: Identifier '%s' not found in any scope\n", expr->value); */
    return -2;
}

void addExpressionToList(Scope *scope, ExprNode *newExpr) {
    // Ensure the scope and new expression are valid
    if (scope == NULL || newExpr == NULL) {
        return;
    }

    // Check if the variable already exists in the current scope
    int i;
    for (i = 0; i < scope->varCount; i++) {
        if (scope->variables[i] != NULL && strcmp(newExpr->value, scope->variables[i]->value) == 0) {
            // Update the existing variable
            scope->variables[i]->stringValue = newExpr->stringValue;
            return; // Updated the existing entry, so no need to add a new one
        }
    }

    // If the variable is not found, add it as a new entry
    // Check if the current scope's variable list is full
    if (scope->varCount >= scope->varSize) {
        // Double the size of the variable list
        scope->varSize *= 2;
        scope->variables = realloc(scope->variables, sizeof(ExprNode*) * scope->varSize);
        // Check for allocation failure
        if (scope->variables == NULL) {
            fprintf(stderr, "Memory reallocation failed for scope variables\n");
            exit(EXIT_FAILURE);
        }
    }

    // Add the new expression to the current scope's variable list
    scope->variables[scope->varCount] = newExpr;
    scope->varCount++;
}

RecipientNode* createRecipientNode(IdentNode ident, char* email) {
    /* printf("\ncreateRecipientNode: Creating recipient node with ident '%s' and email '%s'\n", ident.value, email); */
    RecipientNode* newNode = (RecipientNode*)malloc(sizeof(RecipientNode));
    if (newNode == NULL) {
        /* fprintf(stderr, "Memory allocation failed for RecipientNode\n"); */
        return NULL;
    }

    ExprNode tempExpr;
    tempExpr.value = ident.value;
    int exprId = checkIdentifier(currentScope, &tempExpr);

    if (exprId >= 0 && exprId < exprIndex && expressions[exprId]) {
        // Identifier found, use its string value from expressions array
        newNode->name = strdup(expressions[exprId]->stringValue);
    } else {
        // Identifier not found, use the identifier's name as-is
        newNode->name = strdup(ident.value);
    }

    newNode->email = strdup(email); // Copy the email
    newNode->lineNum = ident.lineNum;
    newNode->next = NULL;
    /* printf("createRecipientNode: Recipient node creation successful\n\n"); */

    return newNode;
}

RecipientNode* createRecipientNodeFromString(char* name, char* email) {
    /* printf("\ncreateRecipientNodeFromString: Creating recipient node with name '%s' and email '%s'\n", name, email); */
    RecipientNode* newNode = (RecipientNode*)malloc(sizeof(RecipientNode));
    if (newNode == NULL) {
        /* fprintf(stderr, "Memory allocation failed for RecipientNode\n"); */
        return NULL;
    }
    newNode->name = name ? strdup(name) : NULL; // Copy the name if it's not NULL
    newNode->email = strdup(email); // Copy the email
    newNode->lineNum = -1; // Line number might not be relevant for string literals
    newNode->next = NULL;
    /* printf("\n\ncreateRecipientNodeFromString: Create recipient node is successful\n"); */

    return newNode;
}

RecipientList* createRecipientList(RecipientNode* firstNode) {
    /* printf("\ncreateRecipientList: Creating new recipient list\n"); */
    RecipientList* newList = (RecipientList*)malloc(sizeof(RecipientList));
    if (newList == NULL) {
        /* fprintf(stderr, "Memory allocation failed for RecipientList\n"); */
        return NULL;
    }
    /* printf("createRecipientList: First node name '%s', email '%s'\n\n", firstNode->name, firstNode->email); */
    newList->head = firstNode;
    return newList;
}

RecipientList* addRecipientToList(RecipientNode* newNode, RecipientList* list) {
    /* printf("\naddRecipientToList: Adding recipient node to list\n"); */
    if (list == NULL) {
        /* fprintf(stderr, "RecipientList is NULL\n"); */
        return NULL;
    }
    if (newNode == NULL) {
        /* fprintf(stderr, "New RecipientNode is NULL\n"); */
        return list;
    }
    /* printf("addRecipientToList: New node name '%s', email '%s'\n\n", newNode->name, newNode->email); */
    // Adding to the end of the list
    newNode->next = list->head;
    list->head = newNode;
    
    return list;
}

ExprNode * makeExpressionNodeFromIdent(IdentNode ident){

    ExprNode * newNode = (ExprNode *)malloc(sizeof(ExprNode));
    newNode->lineNum = ident.lineNum;
    /* printf("\nmakeExpressionNodeFromIdent: New node has line number: %d\n", ident.lineNum); */
    /* newNode->identifier = ident.value; */
    newNode->value = ident.value;
    /* printf("\nmakeExpressionNodeFromIdent: Creating new node value with ident.value: %s\n", ident.value); */
    newNode->stringValue = NULL;
    return newNode;
}

ExprNode * makeExpressionNodeFromString(StringNode str){

    ExprNode * newNode = (ExprNode *)malloc(sizeof(ExprNode));
    /* We only need the value of the value */
    /* newNode->identifier = NULL; */
    newNode->value = NULL;
    /* printf("makeExpressionNodeFromString: Creating new node value with str.value: %s\n", str.value); */
    globalMessage = str.value;
    /* printf("globalMessage: %s\n", globalMessage);
    printf("globalTo: %s\n", globalTo); */
    newNode->lineNum = str.lineNum;
    /* printf("makeExpressionNodeFromString: New node has line number: %d\n", str.lineNum); */
    newNode->stringValue = str.value;
    return newNode;
}

void setIdent (IdentNode * ident1, StringNode * str1){
    // Create a new ExprNode for the identifier
    ExprNode *newExpr = makeExpressionNodeFromIdent(*ident1);
    /* printf("setIdent: Setting newExpr->stringValue to %s\n", str1->value); */
    newExpr->stringValue = str1->value;

    // Add the new expression to the current scope
    addExpressionToList(currentScope, newExpr);
    /* printf("setIdent: Added '%s' to current scope with value '%s'\n", ident1->value, str1->value); */
}

void sendMail(ExprNode *expr1, RecipientList *recipientList, char* currentSenderEmail) {
    /* printf("sendMail: Entered function.\n"); */

    if (expr1 == NULL) {
        /* printf("sendMail: Warning - expr1 is NULL.\n"); */
        return;
    }

    /* printf("sendMail: expr1 is not NULL. Proceeding.\n"); */
    /* printf("sendMail: Checking expr1->value...\n"); */

    char * message;
    if (expr1->value == NULL) {
        /* printf("sendMail: Warning - expr1->value is NULL.\n"); */
        // If expr1 is a string literal, use it directly
        message = strdup(expr1->stringValue);
    } else {
        int exprId = checkIdentifier(currentScope, expr1);
        if (exprId >= 0 && exprId < exprIndex && expressions[exprId] && expressions[exprId]->stringValue) {
            message = strdup(expressions[exprId]->stringValue);
        } else {
            /* printf("sendMail: Identifier not found or no string value, using identifier name: %s\n", expr1->value); */
            message = strdup(expr1->value);
        }
        /* printf("sendMail: expr1->value = %s\n", expr1->value); */
    }

    if (recipientList == NULL) {
        /* printf("sendMail: Warning - recipientList is NULL.\n"); */
        free(message);
        return;
    }
    /* printf("sendMail: Checking expr1->stringValue...\n"); */

    if (expr1->stringValue == NULL) {
    /* printf("sendMail: Warning - expr1->stringValue is NULL.\n"); */
    } else {
        /* printf("sendMail: expr1->stringValue = %s\n", expr1->stringValue); */
    }

    int exprId = checkIdentifier(currentScope, expr1);
    /* printf("sendMail: exprId returned from checkIdentifier is %d\n", exprId); */

    if (exprId >= 0) {
        /* printf("sendMail: Expression found in list. Index: %d\n", exprId); */
    } else if (exprId == -1) {
        /* printf("sendMail: Expression is a string. Value: %s\n", expr1->stringValue); */
    } else {
        /* printf("sendMail: Expression not found. expr1->value: %s\n", expr1->value); */

        error = 1;

        char lineNumStr[20];
        sprintf(lineNumStr, "Test %d", expr1->lineNum);

        int i;
        bool mailFinder = false;
        for (i = 0; i < currentScope->varCount; i++) {
                if (currentScope->variables[i] != NULL) {
                    /* printf("552 Variable %d: %s with value %s\n", i, currentScope->variables[i]->value, currentScope->variables[i]->stringValue); */
                }
                if (strcmp(currentScope->variables[i]->value, expr1->value) == 0) {
                    mailFinder = true;
                    /* printf("556 The values are equal, and you are looking for: %s, and value is: %s\n", expr1->value, currentScope->variables[i]->stringValue); */
                }                
        }
        
        char *src = "ERROR at line %d: %s is undefined\n";
        int buffer = 20;
        int totalLength = strlen(src) + (expr1->value ? strlen(expr1->value) : 0) + strlen(lineNumStr) + buffer;
        /* printf("sendMail: totalLength calculated as %d\n", totalLength); */
        char *dest = (char *)malloc(totalLength);

        if (dest == NULL) {
            /* fprintf(stderr, "Memory allocation failed\n"); */
            return;
        }

        if (!mailFinder){
            sprintf(dest, src, expr1->lineNum, expr1->value ? expr1->value : "NULL");
        }
        
        printf("%s", dest);

        if (errorIndex < errorSize) {
            /* printf("sendMail: Adding error message to existing errors array.\n"); */
            /* printf("sendMail: errorIndex is: %d \n", errorIndex); */
            /* printf("sendMail: errorSize is: %d \n", errorSize); */
            if (dest == NULL) {
                /* fprintf(stderr, "Memory allocation failed\n"); */
                return;
            } else {
                /* printf("sendMail: dest is not NULL\n"); */
            }
            if (errors == NULL) {
                /* printf("sendMail: errors is NULL. Allocating memory space for errors.\n"); */
                errors = malloc(sizeof(char*) * errorSize);
                if (errors == NULL) {
                    /* fprintf(stderr, "Memory allocation failed for errors\n"); */
                    return;
                }
            }
            /* printf("sendMail: Memory allocation for errors is successful.\n"); */
            errors[errorIndex] = dest;
            errorIndex += 1;
            /* printf("sendMail: dest set inside errors with errorIndex\n"); */
        } else {
            /* printf("sendMail: Reallocating errors array due to insufficient space.\n"); */
            errorSize = errorSize + errorSize;
            char **temp = realloc(errors, sizeof(char *) * errorSize);

            if (temp == NULL) {
                /* printf("sendMail: Memory reallocation for errors array failed.\n"); */
                free(dest);
                return;
            }

            errors = temp;
            /* printf("sendMail: Successfully reallocated errors array. Adding error message.\n"); */
            errors[errorIndex] = dest;
            errorIndex += 1;
        }
    }
    /* printf("sendMail: Current Scope has %d variables.\n", currentScope->varCount); */
    int i;
    for (i = 0; i < currentScope->varCount; i++) {
        if (currentScope->variables[i] != NULL) {
            /* printf("Variable %d: %s with value %s\n", i, currentScope->variables[i]->value, currentScope->variables[i]->stringValue); */
        }
    }
      if (recipientList == NULL) {
        /* printf("sendMail: Warning - recipientList is NULL.\n"); */
    } else {
        char *message = (expr1->stringValue != NULL) ? expr1->stringValue : "(No message)";
        
        // Array to keep track of processed emails
        char *processedEmails[100]; // Adjust size as needed
        int processedCount = 0;
        
        RecipientNode *current = recipientList->head;
        RecipientNode *tempCurrent = recipientList->head;
        while (current != NULL) {
            char *recipientInfo;
            char *recipientEmail = current->email;
            bool alreadyProcessed = false;

            int i;
            for (i = 0; i < processedCount; i++) {
                if (strcmp(recipientEmail, processedEmails[i]) == 0) {
                    alreadyProcessed = true;
                    break;
                }
            }
            
            // Check if the recipient's name is an identifier or a string literal
            if (current->name && current->name[0] == '"') {
                // It's a string literal, remove the quotes
                recipientInfo = strdup(current->name + 1);
                recipientInfo[strlen(recipientInfo) - 1] = '\0'; // Remove the ending quote
                /* printf("sendMail: recipientInfo value: %s\n", recipientInfo); */
            } else if (current->name) {
                // It's an identifier, check if it's defined
                ExprNode tempExpr;
                tempExpr.value = current->name;
                int recipientId = checkIdentifier(currentScope, &tempExpr);
                /* printf("sendMail: current->name is: %s\n", current->name); */
                /* printf("sendMail: recipientId is: %d, exprIndex is: %d\n", recipientId, exprIndex); */
                
                int i;
                bool matchFound = false;
                for (i = 0; i < currentScope->varCount; i++) {
                    if (currentScope->variables[i] != NULL) {
                        /* printf("Variable %d: %s with value %s, current->name: %s\n", i, currentScope->variables[i]->value, currentScope->variables[i]->stringValue, current->name); */
                    }
                    if (strcmp(currentScope->variables[i]->value, current->name) == 0) {
                        matchFound = true;
                        /* printf("The values are equal.\n"); */
                    }                
                }
                
                if (recipientId >= 0 && recipientId < exprIndex) {
                    /* printf("sendMail: recipientId >= 0 && recipientId < exprIndex\n"); */
                    if (expressions[recipientId] && expressions[recipientId]->stringValue) {
                            recipientInfo = strdup(expressions[recipientId]->stringValue);
                            /* printf("sendMail: Value of recipientInfo %s\n", recipientInfo); */
                    }
                } else {
                    // Identifier not found, print error and skip
                
                    if (!matchFound){
                        printf("ERROR at line: %d %s is undefined\n", current->lineNum, current->name);
                    } else {
                        char * namePrint = NULL;
                        int i;
                        for (i = 0; i < currentScope->varCount; i++) {
                            if (currentScope->variables[i] != NULL) {
                                /* printf("Variable %d: %s with value %s, current->name: %s\n", i, currentScope->variables[i]->value, currentScope->variables[i]->stringValue, current->name); */
                            }
                            if (strcmp(currentScope->variables[i]->value, current->name) == 0) {
                                namePrint = strdup(currentScope->variables[i]->stringValue + 1);
                                namePrint[strlen(namePrint) - 1] = '\0'; // Remove the ending quote
                                /* printf("The values are equal, and you are looking for: %s\n", currentScope->variables[i]->stringValue); */
                            }                
                        }
                        
                        globalName = namePrint;
                        globalTo = currentSenderEmail;
                        printf("E-mail sent from %s to %s: %s\n", currentSenderEmail, namePrint, tempCurrent->name);
                    }
                    error = 1;
                    /* printf("Walking current\n"); */
                    current = current->next;
                    continue;
                }
            } else {
                // No name provided, use email
                recipientInfo = strdup(current->email);
            }

            // Print the email sent info
            if (!error && !alreadyProcessed){
                    /* printf("785 E-mail sent from %s to %s: %s\n", currentSenderEmail, recipientInfo, message); */
                    // Add email to processed list
                    processedEmails[processedCount++] = recipientEmail;

                    // Determine recipient info to use (name or email)
                    char *recipientInfo = (current->name && current->name[0] != '\0') ? current->name : recipientEmail;
                    if (current->name && current->name[0] == '"') {
                        // It's a string literal, remove the quotes
                        recipientInfo = strdup(current->name + 1);
                        recipientInfo[strlen(recipientInfo) - 1] = '\0'; // Remove the ending quote
                        /* printf("sendMail: recipientInfo value: %s\n", recipientInfo); */
                        
                        ExprNode tempExpr;
                        tempExpr.value = current->name;
                        int recipientId = checkIdentifier(currentScope, &tempExpr);

                        if (recipientId >= 0) {
                            // Identifier found, use its string value
                            recipientInfo = strdup(expressions[recipientId]->stringValue);
                        } else {
                            // No identifier or it's a string literal
                            recipientInfo = strdup(current->name);
                        }
                    }
                    // Print email message
                    if (message != "(No message)"){
                        if (current->name && current->name[0] == '"') {
                            recipientInfo = strdup(current->name + 1);
                            recipientInfo[strlen(recipientInfo) - 1] = '\0'; // Remove the ending quote
                        }
                        globalTo = currentSenderEmail;
                        if (!error){
                            printf("E-mail sent from %s to %s: %s\n", currentSenderEmail, recipientInfo, message);
                        }
                    }
            } else {
                // No name provided, use email
                recipientInfo = strdup(current->email);
            }
            free(recipientInfo);
            current = current->next;
        }
    }


    /* printf("sendMail: Exiting function.\n"); */
}




int main () 
{
    initGlobalScope();
    if (yyparse())
    {
        /* printf("ERROR\n"); */
        return 1;
    } 
    else 
    {
        printScheduledEmails();
        /* printf("OK\n"); */
        return 0;
    } 
}

