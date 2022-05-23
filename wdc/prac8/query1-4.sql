SELECT Students.given_name, Students.family_name, Enrolments.mark
FROM Students
INNER JOIN Enrolments ON subject_code='COMP SCI 2000' AND mark<50 AND Students.student_id = Enrolments.student_id;

