# Write your MySQL query statement below
  select Id,
  case 
      when p_id is null then "Root"
      when (p_id is not null and id in (select p_id from Tree)) then "Inner"
      else "Leaf"
  end as Type
  from tree