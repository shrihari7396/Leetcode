# Write your MySQL query statement below
select score, rnk as "rank"
from (
    select score, dense_rank() over (order by score desc) as rnk
    from scores
) ranked