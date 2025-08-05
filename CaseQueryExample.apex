// Example usage of CaseQueryHelper class
// This script can be executed in Salesforce Developer Console or via Anonymous Apex

// Example 1: Query cases by specific user ID
// Replace 'USER_ID_HERE' with an actual user ID from your org
Id specificUserId = 'USER_ID_HERE'; // e.g., '0053h000004xyzABC'
List<Case> userCases = CaseQueryHelper.queryCasesByCreatedByUser(specificUserId);
System.debug('Found ' + userCases.size() + ' cases for user ID: ' + specificUserId);

// Example 2: Query cases by username
// Replace with an actual username from your org
String username = 'user@example.com'; 
List<Case> userCasesByUsername = CaseQueryHelper.queryCasesByCreatedByUser(username);
System.debug('Found ' + userCasesByUsername.size() + ' cases for username: ' + username);

// Example 3: Query cases for current running user
List<Case> currentUserCases = CaseQueryHelper.queryCurrentUserCases();
System.debug('Found ' + currentUserCases.size() + ' cases for current user');

// Example 4: More detailed example with specific user lookup
// Find a specific user and then query their cases
List<User> users = [SELECT Id, Name, Username FROM User WHERE IsActive = true LIMIT 1];
if (!users.isEmpty()) {
    User sampleUser = users[0];
    System.debug('Querying cases for user: ' + sampleUser.Name + ' (' + sampleUser.Username + ')');
    
    List<Case> cases = CaseQueryHelper.queryCasesByCreatedByUser(sampleUser.Id);
    
    if (!cases.isEmpty()) {
        System.debug('Sample case details:');
        Case firstCase = cases[0];
        System.debug('- Case Number: ' + firstCase.CaseNumber);
        System.debug('- Subject: ' + firstCase.Subject);
        System.debug('- Description: ' + firstCase.Description);
    } else {
        System.debug('No cases found for this user');
    }
}