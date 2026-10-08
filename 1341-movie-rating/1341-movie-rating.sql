# Write your MySQL query statement below



SELECT results
FROM (
    SELECT u.name AS results
    FROM Users u
    JOIN MovieRating m ON u.user_id = m.user_id
    GROUP BY u.user_id, u.name
    ORDER BY COUNT(*) DESC, u.name
    LIMIT 1
) a

UNION ALL

SELECT results
FROM (
    SELECT mo.title AS results
    FROM Movies mo
    JOIN MovieRating m ON mo.movie_id = m.movie_id
    WHERE m.created_at >= '2020-02-01'
      AND m.created_at < '2020-03-01'
    GROUP BY mo.movie_id, mo.title
    ORDER BY AVG(m.rating) DESC, mo.title
    LIMIT 1
) b;