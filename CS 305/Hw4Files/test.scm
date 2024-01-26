(define (twoOperatorCalculator expr)
(define (evaluate-expr expr total last-op)
  (if (null? expr) total  
      (let ((current (car expr)))
        (cond ((number? current)
          (begin (evaluate-expr (cdr expr)
                            (case last-op
                              ((+) (begin (+ total current)))
                              ((-) (begin (- total current)))
                              (else current)) last-op)))
          ((member current '(+ -))
          (begin (evaluate-expr (cdr expr) total current)))
          (else (error "twoOperatorCalculator: Invalid operator" current))))))
(if (null? expr) 0
  (if (member (car expr) '(+ -))
    (evaluate-expr (cddr expr) (cadr expr) (car expr))
(evaluate-expr (cdr expr) (car expr) '+))))


(define (fourOperatorCalculator lst)
; Check if the list contains only one element. If so, return the list itself.
(if (null? (cdr lst))
  lst
  ; Check if the second element of the list is the * operator.
  (if (eq? '* (cadr lst))
      ; If it's *, create a new list where the first element is the result of multiplication,
      ; and the rest of the list is processed recursively.
      (fourOperatorCalculator (cons (* (car lst) (caddr lst)) (cdddr lst)))
      ; If the second element is /, create a new list with the result of division and process the rest.
      (if (eq? '/ (cadr lst))
          (fourOperatorCalculator (cons (/ (car lst) (caddr lst)) (cdddr lst)))
          ; If neither * nor /, keep the current element and process the rest of the list.
          (cons (car lst) (fourOperatorCalculator (cdr lst)))))))

; Take a look bak again
(define (calculatorNested lst)
(if (checkOperators lst) 
(map (lambda (element)
(if (list? element)
            (twoOperatorCalculator(fourOperatorCalculator(calculatorNested element)))
            element)) lst)
#f))

; 305 Lecture note page
(define (checkOperators sequence)
(cond ((or (null? sequence) (not (list? sequence))) #f)
      ((and (number? (car sequence)) (null? (cdr sequence))) #t)
      ((and (list? (car sequence)) (null? (cdr sequence)))
        (checkOperators (car sequence)))
      ((and (number? (car sequence)) (member (cadr sequence) '(+ - * /)))
        (checkOperators (cddr sequence)))
      ((and (list? (car sequence)) (member (cadr sequence) '(+ - * /)))
        (and (checkOperators (car sequence)) (checkOperators (cddr sequence))))
      (else #f)))

(define (calculator lst)
(if (checkOperators lst)
  (twoOperatorCalculator(fourOperatorCalculator(calculatorNested lst)))
#f))

; ; Test twoOperatorCalculator
; (newline)
; (define test1 (twoOperatorCalculator '(+ 1 2))) ; 3
;   (if (= test1 3) (display "twoOperatorCalculator 1: PASSED") (display "twoOperatorCalculator 1: FAILED"))
; (newline)

; (define test2 (twoOperatorCalculator '(1 + 2))) ; 3
;   (if (= test2 3) (display "twoOperatorCalculator 2: PASSED") (display "twoOperatorCalculator 2: FAILED"))
; (newline)

; (define test3 (twoOperatorCalculator '(1 + 2 + 3 + 4 + 5))) ; 15
; (if (= test3 15) (display "twoOperatorCalculator 3: PASSED") (display "twoOperatorCalculator 3: FAILED"))
; (newline)

; (define test4 (twoOperatorCalculator '(1 + 2 - 3 + 3 - 3 - 3 + 1 - -3))) ; 
; (if (= test4 1) (display "twoOperatorCalculator 4: PASSED") (display "twoOperatorCalculator 4: FAILED"))
; (newline)

; (define test5 (twoOperatorCalculator '(32/5))) ; 
; (if (= test5 32/5) (display "twoOperatorCalculator 5: PASSED") (error "twoOperatorCalculator 5: FAILED --> " test5))
; (newline)

; (define test6 (twoOperatorCalculator '(1))) ; 
; (if (= test6 1 ) (display "twoOperatorCalculator 6: PASSED") (display "twoOperatorCalculator 6: FAILED"))
; (newline)

; (define test7 (twoOperatorCalculator '(1 + 2))) ; 
; (if (= test7 3 ) (display "twoOperatorCalculator 7: PASSED") (display "twoOperatorCalculator 7: FAILED"))
; (newline)

; (define test8 (twoOperatorCalculator '(1 + -2))) ; 
; (if (= test8 -1 ) (display "twoOperatorCalculator 8: PASSED") (display "twoOperatorCalculator 8: FAILED"))
; (newline)

; (define test9 (twoOperatorCalculator '(2 - 1 + 3 + 1))) ; 
; (if (= test9 5 ) (display "twoOperatorCalculator 9: PASSED") (display "twoOperatorCalculator 9: FAILED"))
; (newline)

; (define test10 (twoOperatorCalculator '(1 + 15 - 32/5 + -2))) ; 
; (if (= test10 38/5 ) (display "twoOperatorCalculator 10: PASSED") (error "twoOperatorCalculator 10: FAILED -->" test10))
; (newline)
; (newline)
; ; Test fourOperatorCalculator
; (display "Results for fourOperatorCalculator:")
; (newline)
; (display (fourOperatorCalculator '(2 * 3)))
; (newline)
; (display (fourOperatorCalculator '(6 / 2)))
; (newline)
; (display (fourOperatorCalculator '(1 + 3 * 5 - 4 / 5 * 8 + 2 * -1)))
; (newline)
; (newline)

; ; Test for checkOperators
; (display "Results for checkOperators:")
; (newline)
; (define test11  ( checkOperators '(1) )) ; 
; (if (equal? test11 #t ) (display "checkOperators 1: PASSED") (error "checkOperators 1: FAILED -->" test11))
; (newline)
; (define test12  ( checkOperators '((((1) ) ) ))) ; 
; (if (equal? test12 #t ) (display "checkOperators 2: PASSED") (error "checkOperators 2: FAILED -->" test12))
; (newline)
; (define test13  ( checkOperators '(1 + (1 + 1 * -2) * 5 - -4 / 5 * 8 + (5 - 3) * -1) )) ; 
; (if (equal? test13 #t ) (display "checkOperators 3: PASSED") (error "checkOperators 3: FAILED -->" test13))
; (newline)
; (define test14  (checkOperators  '( checkOperators '(+ 1 3) ))); 
; (if (equal? test14 #f ) (display "checkOperators 4: PASSED") (error "checkOperators 4: FAILED -->" test14))
; (newline)
; (define test15  (checkOperators   '( checkOperators '(1 < 3) ))); 
; (if (equal? test15 #f ) (display "checkOperators 5: PASSED") (error "checkOperators 5: FAILED -->" test15))
; (newline)
; (define test16  (checkOperators   ' ( checkOperators '(1)))); 
; (if (equal? test16 #f ) (display "checkOperators 6: PASSED") (error "checkOperators 6: FAILED -->" test16))
; (newline)

; ; Tests for calculator
; (newline)
; (display "Results for calculator:")
; (newline)
; (define test17  ( calculator '(1) )) ; 
; (if (equal? test17 1 ) (display "calculator 1: PASSED") (error "calculator 1: FAILED -->" test17))
; (newline)
; (define test18  (  calculator '(1 + (1 + 1 * 2) * 5 - 4 / 5 * 8 + (5 - 3) * -1) )) ; 
; (if (equal? test18 38/5 ) (display "calculator 2: PASSED") (error "calculator 2: FAILED -->" test18))
; (newline)
; (define test19  (   calculator '(2 * (1 + (1 + (1 + (1 + (1 + ((1) ) )) ) ) ) ) )) ; 
; (if (equal? test19 12 ) (display "calculator 3: PASSED") (error "calculator 3: FAILED -->" test19))
; (newline)
; (define test20  (   calculator '(1 -2) )) ; 
; (if (equal? test20 #f ) (display "calculator 4: PASSED") (error "calculator 4: FAILED -->" test20))
; (newline)
; (define test21  (   calculator '(1 < 3) )) ; 
; (if (equal? test21 #f ) (display "calculator 5: PASSED") (error "calculator 5: FAILED -->" test21))
; (newline)
; (define test22  (   calculator '1 )) ; 
; (if (equal? test22 #f ) (display "calculator 6: PASSED") (error "calculator 6: FAILED -->" test22))
; (newline)