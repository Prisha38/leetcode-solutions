# Write your MySQL query statement below



(
    SELECT u.name AS results
    FROM Users u
    JOIN MovieRating m ON u.user_id = m.user_id
    GROUP BY u.name
    ORDER BY COUNT(*) DESC, u.name
    LIMIT 1
)
UNION ALL
(
    SELECT mo.title AS results
    FROM Movies mo
    JOIN MovieRating m ON mo.movie_id = m.movie_id
    WHERE MONTH(m.created_at) = 2
      AND YEAR(m.created_at) = 2020
    GROUP BY mo.title
    ORDER BY AVG(m.rating) DESC, mo.title
    LIMIT 1
);