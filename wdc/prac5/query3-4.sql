SELECT given_name, family_name
FROM Students
INNER JOIN Enrolments ON subject_code='COMP SCI 2207' AND Students.student_id = Enrolments.student_id;