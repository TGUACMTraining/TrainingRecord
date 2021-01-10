double left,right,mid;
while (right-left>eps)
{
mid=(right+left)/2;
if(judge(mid))left=mid;
else right=mid;
}
return mid;