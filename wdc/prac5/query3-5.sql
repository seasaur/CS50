SELECT given_name, family_name
FROM Students
WHERE student_id = ALL
  (SELECT student_id
  FROM Enrolments
  WHERE mark < 50);