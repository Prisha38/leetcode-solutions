


# Write your MySQL query statement below
WITH duplicates AS (
    SELECT id,
           ROW_NUMBER() OVER (
               PARTITION BY email
               ORDER BY id
           ) AS rn
    FROM Person 
)
DELETE 
FROM Person 
WHERE id IN (
    SELECT id
    FROM duplicates
    WHERE rn > 1
);