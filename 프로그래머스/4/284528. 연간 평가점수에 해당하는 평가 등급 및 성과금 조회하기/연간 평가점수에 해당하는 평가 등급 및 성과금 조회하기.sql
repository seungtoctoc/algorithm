with GRADE_AVER as (
    select EMP_NO, YEAR, avg(SCORE) SCORE
    from HR_GRADE
    group by EMP_NO, YEAR
)

select e.EMP_NO, e.EMP_NAME,
    case
        when g.SCORE >= 96 then 'S'
        when g.SCORE >= 90 then 'A'
        when g.SCORE >= 80 then 'B'
        else 'C'
    end as GRADE,
    case
        when g.SCORE >= 96 then e.SAL * 0.2
        when g.SCORE >= 90 then e.SAL * 0.15
        when g.SCORE >= 80 then e.SAL * 0.1
        else 0
    end as BONUS
from HR_EMPLOYEES e left join GRADE_AVER g
on e.EMP_NO = g.EMP_NO
order by e.EMP_NO;