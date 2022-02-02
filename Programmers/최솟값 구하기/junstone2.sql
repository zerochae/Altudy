SELECT a.datetime
  from (select datetime from animal_ins order by datetime asc) a
 where rownum <= 1