1.
    select teachers.name,courses.name
     from teachers 
     left join courses on
        courses.id=teachers.id


2.
    select teachers.name,count(*) as Total_course_taken
     from teachers 
     left join courses 
     on courses.id=teachers.id
     group by courses.teacher_id
     order by count(*) desc
     limit 1


3.
    select teachers.name 
    from teachers
    where teachers.id not in (
        select courses.teacher_id
        from courses 
        )
