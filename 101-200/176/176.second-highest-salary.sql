--
-- @lc app=leetcode id=176 lang=mysql
--
-- [176] Second Highest Salary
--
# Write your MySQL query statement below


select max(Salary) as SecondHighestSalary
from (
    select Salary 
    from Employee 
    where Salary < (
        select distinct Salary 
        from Employee
        where Salary >= all (select Salary from Employee)
    )
) as NewSalaryTable;

