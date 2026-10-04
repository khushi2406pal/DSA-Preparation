/*
===========================================================
Problem: Find All Possible Recipes from Given Supplies
LeetCode: 2115
Difficulty: Medium

Description:
Given a list of recipes, their required ingredients, and
initial supplies, return all recipes that can be created.

A recipe can also be used as an ingredient for another recipe.

Example:
Input:
recipes = ["bread", "sandwich"]
ingredients = [["yeast", "flour"],
               ["bread", "meat"]]
supplies = ["yeast", "flour", "meat"]

Output:
["bread", "sandwich"]

Explanation:
- "bread" can be created using yeast and flour.
- Once bread is available, "sandwich" can be created.

Approach:
Use a queue to repeatedly process recipes whose ingredients
may become available.

1. Store all initial supplies in an unordered_set.
2. Add all recipe indices to a queue.
3. Process the recipes currently in the queue.
4. If all ingredients of a recipe are available:
   - Create the recipe.
   - Add it to the available set.
   - Add it to the answer.
5. If a recipe cannot currently be created, put it back into
   the queue for another round.
6. Stop when no new items are added to the available set.

This works because creating one recipe can make another recipe
possible.

Time Complexity: O(total number of ingredient checks)
Space Complexity: O(number of recipes + number of supplies)

===========================================================
*/
#include<vector>
#include<string>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {

        // Store all currently available ingredients and recipes
        unordered_set<string> available(
            supplies.begin(),
            supplies.end()
        );

        // Queue containing recipe indices
        queue<int> recipeQueue;

        for (int i = 0; i < recipes.size(); i++) {
            recipeQueue.push(i);
        }

        vector<string> createdRecipes;

        int lastSize = -1;

        // Continue while new recipes are being created
        while (static_cast<int>(available.size()) > lastSize) {

            lastSize = available.size();

            int queueSize = recipeQueue.size();

            // Process recipes from the current round
            while (queueSize-- > 0) {

                int recipeIdx = recipeQueue.front();
                recipeQueue.pop();

                bool canCreate = true;

                // Check whether all ingredients are available
                for (string& ingredient : ingredients[recipeIdx]) {

                    if (!available.count(ingredient)) {
                        canCreate = false;
                        break;
                    }
                }

                if (!canCreate) {
                    // Try again in a later round
                    recipeQueue.push(recipeIdx);
                }
                else {
                    // Recipe can now be created
                    available.insert(recipes[recipeIdx]);
                    createdRecipes.push_back(recipes[recipeIdx]);
                }
            }
        }

        return createdRecipes;
    }
};