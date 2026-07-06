# Write your MySQL query statement below
SELECT e3.`name` 'Department', e2.`name` Employee, e2.salary Salary FROM employee e2 
INNER JOIN (SELECT * FROM (SELECT max(e1.salary) maxSalary, departmentId 
FROM employee e1
GROUP BY departmentId) ed INNER JOIN department d ON d.id = ed.departmentId) e3
ON e2.departmentId = e3.departmentId
WHERE e2.salary = e3.maxSalary;