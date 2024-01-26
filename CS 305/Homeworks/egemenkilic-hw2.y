%{
#include <stdio.h>
void yyerror (const char *msg) {
    return; 
}
%}

%token tMAIL tENDMAIL tSCHEDULE tENDSCHEDULE tSEND tSET tTO tFROM tAT tCOMMA tCOLON tLPR tRPR tLBR tRBR tIDENT tSTRING tADDRESS tDATE tTIME  
%start program

%%

/* 
    * Schedule and send can only be in a mail block
*/

program:    mailBlock program
            | set program
            | 
;

/* 
    Mail from serkan@sabanciuniv.edu: 
*/
mailBlock:  tMAIL tFROM tADDRESS tCOLON mailContent tENDMAIL
;

/* 
    Mail from melis@sumail.com:
        set Content ("Meeting at 5pm.")
        set Content ("Meeting at 5pm.")
        set Content ("Meeting at 5pm.")
        set Content ("Meeting at 5pm.")
        set Content ("Meeting at 5pm.")
    end Mail
*/
mailContent:  schedule mailContent 
            | set mailContent
            | send mailContent
            |
;



/* 
    set Notification ("Don't forget to set the alarm.") 
    set UserName ("There is a meeting at 3pm.")
*/
set:    tSET tIDENT tLPR tSTRING tRPR
;


sendList: send
            | send sendList
;


/* 
    send ["Good morning!"] to [(user1@mail.com)]
    send [Message] to [(user2@mail.com)]
    send ["Please check the gradebook."] to [(example@mail.com), (admin123@mail.com)]
*/
send:   tSEND tLBR tIDENT tRBR tTO tLBR recipientList tRBR
            | tSEND tLBR tSTRING tRBR tTO tLBR recipientList tRBR
;


recipientList:   recipient  
            |  recipient tCOMMA recipientList
;


recipient:  tLPR tADDRESS tRPR // (example@mail.com)
            |   tLPR tSTRING tCOMMA tADDRESS tRPR // ("Mehmet", user_475@some-company.co.uk)
            |   tLPR tIDENT tCOMMA tADDRESS tRPR 
            /* | tLBR recipient tRBR // [("Ayse", ayse3@thismail.com), ("Unknown User", user8564@mail.com), (seyma@example.de)] */
;


/* 
    schedule @ [18/10/2021, 12:00]:
*/
schedule: tSCHEDULE tAT tLBR tDATE tCOMMA tTIME tRBR tCOLON sendList tENDSCHEDULE
;

%%

int main()  
{
    if (yyparse())
    {
        /* parse error */
        printf("ERROR\n");
        return 1;
    }
    else 
    {
        printf("OK\n");
        return 0;
    }
}
