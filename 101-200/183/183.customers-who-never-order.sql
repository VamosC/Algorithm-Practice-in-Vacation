--
-- @lc app=leetcode id=183 lang=mysql
--
-- [183] Customers Who Never Order
--
# Write your MySQL query statement below

select Name as Customers
from Customers as S
where not exists (
    select *
    from Orders as T
    where S.id = T.CustomerId
);

