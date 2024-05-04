-- 코드를 작성해주세요

select ii.ITEM_ID, ii.ITEM_NAME
from ITEM_INFO ii join ITEM_TREE it
on ii.ITEM_ID = it.ITEM_ID
where it.PARENT_ITEM_ID is null
order by ii.ITEM_ID