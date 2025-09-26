public class SecondMax {
    
    public static Integer findSecondMax(int[] arr) {
        // Проверка на минимальную длину
        if (arr == null || arr.length < 2) {
            return null;
        }
        
        int max = Integer.MIN_VALUE;
        int secondMax = Integer.MIN_VALUE;
        
        for (int num : arr) {
            if (num > max) {
                // Обновляем второй максимум старым значением max
                secondMax = max;
                // Обновляем текущий максимум
                max = num;
            } else if (num > secondMax && num < max) {
                // Обновляем второй максимум, если число между current max и secondMax
                secondMax = num;
            }
        }
        
        // Проверяем, был ли найден второй максимум
        return (secondMax == Integer.MIN_VALUE) ? null : secondMax;
    }
    
    public static void main(String[] args) {
        int[] array = {10, 5, 8, 10, 15, 3};
        Integer result = findSecondMax(array);
        System.out.println("Второй максимум: " + result); // Вывод: 10
    }
}