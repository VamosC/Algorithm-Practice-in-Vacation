--
-- @lc app=leetcode id=175 lang=mysql
--
-- [175] Combine Two Tables
--
# Write your MySQL query statement below
select FirstName, LastName, City, State
from Person natural left outer join Address;

