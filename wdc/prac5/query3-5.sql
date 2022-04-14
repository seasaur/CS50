SELECT given_name, family_name
FROM Students
WHERE mark = ALL
  (SELECT student_id
  FROM Enrolments
  WHERE mark < 50);