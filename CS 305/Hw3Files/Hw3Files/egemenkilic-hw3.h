#ifndef __EGEMENKILIC_HW3
#define __EGEMENKILIC_HW3

typedef struct IdentNode
{
    int lineNum;
    char *value;
} IdentNode;

typedef struct StringNode
{
   int lineNum;
   char *value;
} StringNode;

typedef struct ExprNode
{
    int lineNum;
    char *stringValue;
    char *value;
} ExprNode;

typedef struct RecipientNode{
    char* name;
    char* email;
    int lineNum;
   struct RecipientNode *next;

} RecipientNode;

typedef struct RecipientList{
    RecipientNode* head;
} RecipientList;

typedef struct Scope {
    ExprNode **variables;
    int varCount;
    int varSize;
    struct Scope *parent;
} Scope;

typedef struct ScheduledEmail {
    char *date;
    char *time;
    char *senderEmail;
    char *recipientInfo;
    char *message;
    int lineNum; // For sorting in case of same date and time
    struct ScheduledEmail *next;
} ScheduledEmail;

#endif
