# Write your MySQL query statement below
select distinct actor_id , director_id from ActorDirector 
group by actor_id , director_id having count(*) >=3