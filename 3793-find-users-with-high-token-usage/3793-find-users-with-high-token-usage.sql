# Write your MySQL query statement below




SELECT user_id, COUNT(DISTINCT prompt) AS prompt_count,
ROUND(AVG(tokens),2) AS avg_tokens
FROM prompts
GROUP BY user_id
HAVING prompt_count >= 3  AND MAX(tokens) > AVG(tokens)
ORDER BY avg_tokens DESC



