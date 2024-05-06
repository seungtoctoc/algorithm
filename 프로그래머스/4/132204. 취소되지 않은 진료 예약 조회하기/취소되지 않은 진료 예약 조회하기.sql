-- 코드를 입력하세요

select a.APNT_NO, p.PT_NAME, p.PT_NO, d.MCDP_CD, d.DR_NAME, a.APNT_YMD
from PATIENT p right join APPOINTMENT a 
    on p.PT_NO = a.PT_NO
    left join DOCTOR d
    on a.MDDR_ID = DR_ID
where DATE_FORMAT(a.APNT_YMD, '%Y%m%d') = '20220413' and a.APNT_CNCL_YN = 'N' and d.MCDP_CD = 'CS'
order by a.APNT_YMD