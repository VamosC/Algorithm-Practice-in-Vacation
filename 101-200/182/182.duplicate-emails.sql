--
-- @lc app=leetcode id=182 lang=mysql
--
-- [182] Duplicate Emails
--
# Write your MySQL query statement below

select Email
from Person
group by Email
having count(Id) > 1;

