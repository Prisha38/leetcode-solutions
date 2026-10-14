# Write your MySQL query statement below
WITH non_returned_copies AS (
	SELECT 
		book_id,
        COUNT(1) AS Total_non_returned_copies
	FROM borrowing_records 
    WHERE return_date IS NULL
    GROUP BY book_id
)
SELECT
	lb.book_id,
	lb.title,
    lb.author,
    lb.genre,
    lb.publication_year,
    lb.total_copies AS current_borrowers 
FROM library_books lb 
JOIN non_returned_copies nrc ON lb.book_id = nrc.book_id
WHERE lb.total_copies = nrc.Total_non_returned_copies
ORDER BY current_borrowers DESC, lb.title ASC;