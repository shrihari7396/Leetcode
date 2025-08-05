# Write your MySQL query statement below

select w.id from Weather w join Weather w1 on datediff(w.recordDate , w1.recordDate) = 1 and w.temperature > w1.temperature;
