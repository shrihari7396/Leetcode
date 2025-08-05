SELECT w.id
FROM Weather w
JOIN Weather w1 
  ON w.recordDate = DATE_ADD(w1.recordDate, INTERVAL 1 DAY)
WHERE w.temperature > w1.temperature;
