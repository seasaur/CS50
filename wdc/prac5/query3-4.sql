

SELECT student_id
FROM Enrolments
INNER JOIN Students ON Orders.CustomerID = Customers.CustomerID;
WHERE subject_code='COMP SCI 2207';

SELECT given_name, family_name
FROM Students
WHERE student_id='BCompSc';