# SELECT score, dense_rank() OVER(ORDER BY score DESC) as "rank"
# FROM Scores

# SELECT s1.score, s1.id FROM Scores AS S1 JOIN Scores AS S2 ON s2.id = s1.id-1
# GROUP BY s1.id;

select score, (select count(distinct score) from scores s2 where s2.score >= s1.score) as "Rank"
from scores s1
order by score desc;