SELECT datetime
  from (select datetime from animal_ins order by datetime desc)
  where rownum = 1;