/*JONATHAN ADITHYA BASWARA 5027221062*/
/* No 1 */
SELECT student.name_student, task.desc_task, course.name_course, lecturer.name_lecturer
FROM task
INNER JOIN course
ON task.id_mk = course.id
INNER JOIN student
ON task.id_mhs = student.id
INNER JOIN lecturer
ON task.id_dos = lecturer.id;

/* No 2 */
SELECT student.name_student, task.desc_task, course.name_course, lecturer.name_lecturer 
FROM task
INNER JOIN student 
ON task.id_mhs = student.id
INNER JOIN lecturer
ON task.id_dos = lecturer.id
INNER JOIN course
ON task.id_mk = course.id
WHERE lecturer.name_lecturer LIKE 'H%';

/* No 3 */
SELECT student.name_student, task.desc_task, course.name_course, lecturer.name_lecturer 
FROM task
INNER JOIN student 
ON task.id_mhs = student.id
INNER JOIN lecturer
ON task.id_dos = lecturer.id
INNER JOIN course
ON task.id_mk = course.id
WHERE task.score BETWEEN 60 AND 80;

/* No 4 */
SELECT student.name_student, student.nrp
FROM task
RIGHT JOIN student 
ON task.id_mhs = student.id
WHERE task.id is NULL;