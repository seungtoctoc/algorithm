-- 코드를 작성해주세요
select SUM(g.SCORE) SCORE, e.EMP_NO, e.EMP_NAME, e.POSITION, e.EMAIL
from HR_EMPLOYEES e join HR_GRADE g
on e.EMP_NO = g.EMP_NO
group by g.EMP_NO
order by SCORE desc
limit 1;

