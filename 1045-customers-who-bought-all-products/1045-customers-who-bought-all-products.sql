# Write your MySQL query statement below
select distinct(c.customer_id) from customer c join Product p on c.product_key = p.product_key
group by c.customer_id
having count(DISTINCT p.product_key) = (select count(*) from Product)
order by c.customer_id;

