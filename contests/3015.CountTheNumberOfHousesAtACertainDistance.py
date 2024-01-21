class Solution:
    def countOfPairs(self, n: int, x: int, y: int) -> List[int]:
        result = [0] * n

        # Iterate through all possible pairs of houses
        for i in range(1, n + 1):
            for j in range(i + 1, n + 1):
                # Calculate the minimum streets required to reach house j from house i
                min_streets = min(abs(j - i), abs(x - i) + 1 + abs(y - j), abs(y - i) + 1 + abs(x - j))

                # Increment the count in the result array for the calculated minimum streets
                result[min_streets - 1] += 2

        return result
