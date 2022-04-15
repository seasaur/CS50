SELECT given_name, family_name
FROM Students
WHERE student_id = ALL
  (SELECT student_id
  FROM Enrolments
  WHERE mark < 50);

SELECT Students.given_name, Students.family_name, Enrolments.mark
FROM Enrolments
INNER JOIN Enrolments ON subject_code='COMP SCI 2000' AND mark<50 AND Students.student_id = Enrolments.student_id;