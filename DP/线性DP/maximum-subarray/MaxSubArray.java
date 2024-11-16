import java.util.Vector;

public class MaxSubArray {
    public Vector<Integer> FindMaxCrossingSubArray(int[] A, int low, int mid, int high){
        int leftSum = Integer.MIN_VALUE;
        int sum = 0;
        int maxLeft = 0;
        for(int i = mid; i>=low;i--){
            sum = sum +A[i];
            if(sum>leftSum){
                leftSum = sum;
                maxLeft = i;
            }
        }
        int rightSum = Integer.MIN_VALUE;
        int maxRight = 0;
        sum = 0;
        for(int i = mid+1;i<=high;i++){
            sum = sum+A[i];
            if(sum>rightSum){
                rightSum = sum;
                maxRight = i;
            }
        }
        Vector<Integer> result = new Vector<Integer>();
        result.add(maxLeft);
        result.add(maxRight);
        result.add(leftSum+rightSum);
        return result;
    }

    public Vector<Integer> FindMaximumSubArray(int[] A,int low,int high){
        if(high==low){
            Vector<Integer> result = new Vector<Integer>();
            result.add(low);
            result.add(high);
            result.add(A[low]);
            return result;
        }else{
            int mid =(low+high)/2;
            Vector<Integer> leftResult = FindMaximumSubArray(A,low,mid);
            Vector<Integer> rightResult = FindMaximumSubArray(A,mid+1,high);
            Vector<Integer> crossResult = FindMaxCrossingSubArray(A,low,mid,high);
            if(leftResult.get(2)>=rightResult.get(2) && leftResult.get(2)>=crossResult.get(2)){
                return leftResult;
            }else if(rightResult.get(2)>=leftResult.get(2) && rightResult.get(2)>=crossResult.get(2)){
                return rightResult;
            }else{
                return crossResult;
            }
        }
    }

    public static void main(String[] args) {
        MaxSubArray m = new MaxSubArray();
        int[] A = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
        Vector<Integer> result = m.FindMaximumSubArray(A,0,A.length-1);
        System.out.println("Low: "+result.get(0));
        System.out.println("High: "+result.get(1));
        System.out.println("Sum: "+result.get(2));
    }
}
