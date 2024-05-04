select info.FISH_COUNT, name.FISH_NAME
from
(
    select count(*) FISH_COUNT, FISH_TYPE
    from FISH_INFO
    group by FISH_TYPE
) info left join FISH_NAME_INFO name
on info.FISH_TYPE = name.FISH_TYPE
order by FISH_COUNT desc


