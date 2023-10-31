# Dokumentasi Tugas SQL Query #2

Jonathan Adithya Baswara 5027221062

```sql
/* No 1 */
SELECT student.name_student, task.desc_task, course.name_course, lecturer.name_lecturer
FROM task
INNER JOIN course
ON task.id_mk = course.id
INNER JOIN student
ON task.id_mhs = student.id
INNER JOIN lecturer
ON task.id_dos = lecturer.id;
```

![Screenshot from 2023-10-30 22-11-41.png](https://github.com/jonathan-dotcom/StrukduttdanOOP/tree/main/TugasSQLquery%232/Dokumentasi%20Tugas%20SQL%20Query%20%232/Screenshot_from_2023-10-30_22-11-41.png?raw=true)

Screenshot hasil

![Screenshot from 2023-10-30 23-22-44.png](https://github.com/jonathan-dotcom/StrukduttdanOOP/tree/main/TugasSQLquery%232/Dokumentasi%20Tugas%20SQL%20Query%20%232/Screenshot_from_2023-10-30_23-22-44.png?raw=true)

Jumlah = 100

```sql
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
```

![Screenshot from 2023-10-30 22-50-49.png](https://github.com/jonathan-dotcom/StrukduttdanOOP/tree/main/TugasSQLquery%232/Dokumentasi%20Tugas%20SQL%20Query%20%232/Screenshot_from_2023-10-30_22-50-49.png?raw=true)

Jumlah = 3

```sql
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
```

![Screenshot from 2023-10-30 22-54-12.png](https://github.com/jonathan-dotcom/StrukduttdanOOP/tree/main/TugasSQLquery%232/Dokumentasi%20Tugas%20SQL%20Query%20%232/Screenshot_from_2023-10-30_22-54-12.png?raw=true)

Screenshot hasil

![Screenshot from 2023-10-30 23-24-47.png](https://github.com/jonathan-dotcom/StrukduttdanOOP/tree/main/TugasSQLquery%232/Dokumentasi%20Tugas%20SQL%20Query%20%232/Screenshot_from_2023-10-30_23-24-47.png?raw=true)

Jumlah = 18

```sql
/* No 4 */
SELECT student.name_student, student.nrp
FROM task
RIGHT JOIN student 
ON task.id_mhs = student.id
WHERE task.id is NULL;
```

![Screenshot from 2023-10-30 23-02-33.png](https://github.com/jonathan-dotcom/StrukduttdanOOP/tree/main/TugasSQLquery%232/Dokumentasi%20Tugas%20SQL%20Query%20%232/Screenshot_from_2023-10-30_23-02-33.png?raw=true)

Screenshot hasil

![Screenshot from 2023-10-30 23-25-53.png](https://github.com/jonathan-dotcom/StrukduttdanOOP/tree/main/TugasSQLquery%232/Dokumentasi%20Tugas%20SQL%20Query%20%232/Screenshot_from_2023-10-30_23-25-53.png?raw=true)

Jumlah = 438