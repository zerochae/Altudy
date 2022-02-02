----------------oracle-----------------------
SELECT a.datetime
  from (select datetime from animal_ins order by datetime asc) a
 where rownum <= 1

----------------my sql-----------------------
SELECT a.datetime as 시간
  from (select datetime from animal_ins order by datetime asc) as a
 limit 1