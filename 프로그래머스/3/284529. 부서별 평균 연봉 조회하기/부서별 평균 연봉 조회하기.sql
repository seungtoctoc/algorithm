-- 코드를 작성해주세요
select e.DEPT_ID, d.DEPT_NAME_EN, e.AVG_SAL
from HR_DEPARTMENT d right join
(
    select DEPT_ID, round(avg(SAL), 0) AVG_SAL
    from HR_EMPLOYEES
    group by DEPT_ID
) e
on d.DEPT_ID = e.DEPT_ID
order by AVG_SAL desc