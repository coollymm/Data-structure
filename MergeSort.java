public class Mergesort {
    private int count = 0;  //number of reverse pairs

    //[left, right]
    public void mergesort(int[] nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int middle = (left + right) >> 1;
        mergesort(nums, left, middle);
        mergesort(nums, middle + 1, right);
        merge(nums, left, middle, right);
    }

    private void merge(int[] nums, int left, int middle, int right) {
        int i = left;
        int j = middle + 1;
        int k = 0;
        int[] temp = new int[right - left + 1];
        while (i <= middle && j <= right) {
            if(nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
                count += middle - i; //count reverse pair
            }
        }

        while (i <= middle) {
            temp[k++] = nums[i++];
        }
        while (j <= right) {
            temp[k++] = nums[j++];
        }
        for (int m = 0; m <= right - left; m++) {
            nums[left + m] = temp[m];
        }
    }

    public int get_reverse_pair(int[] nums, int length) {
        count = 0;
        mergesort(nums, 0, length - 1);
        return count;
    }

    public static void main(String[] args) {
        Mergesort m = new Mergesort();
        int nums1[] = {2,4,5,7,1,8,3,9};
        //m.mergesort(nums1, 0, nums1.length-1);
        //System.out.println(Arrays.toString(nums1));
        assert (m.get_reverse_pair(nums1, nums1.length) == 3);
    }
}
