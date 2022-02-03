---------------------oracle---------------------
SELECT HOUR, (SELECT COUNT(DATETIME) 
                FROM ANIMAL_OUTS 
               WHERE HOUR = TO_CHAR(DATETIME,'HH24')) AS COUNT
  FROM (SELECT (LEVEL-1) AS HOUR
          FROM DUAL
       CONNECT BY LEVEL <= 24)