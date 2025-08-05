public class CaseQueryHelper {
    
    /**
     * Query cases created by a specific user and log their subject and description
     * @param createdByUserId The ID of the user who created the cases
     * @return List of cases created by the specified user
     */
    public static List<Case> queryCasesByCreatedByUser(Id createdByUserId) {
        // Validate input parameter
        if (createdByUserId == null) {
            System.debug('Error: createdByUserId cannot be null');
            return new List<Case>();
        }
        
        try {
            // Query cases created by the specified user
            List<Case> cases = [
                SELECT Id, CaseNumber, Subject, Description, CreatedById, CreatedBy.Name, CreatedDate, Status
                FROM Case 
                WHERE CreatedById = :createdByUserId
                ORDER BY CreatedDate DESC
            ];
            
            System.debug('Found ' + cases.size() + ' case(s) created by user ID: ' + createdByUserId);
            
            // Log subject and description for each case
            for (Case c : cases) {
                System.debug('=== Case Details ===');
                System.debug('Case Number: ' + c.CaseNumber);
                System.debug('Case ID: ' + c.Id);
                System.debug('Subject: ' + (c.Subject != null ? c.Subject : 'No Subject'));
                System.debug('Description: ' + (c.Description != null ? c.Description : 'No Description'));
                System.debug('Status: ' + c.Status);
                System.debug('Created By: ' + c.CreatedBy.Name);
                System.debug('Created Date: ' + c.CreatedDate);
                System.debug('====================');
            }
            
            return cases;
            
        } catch (Exception e) {
            System.debug('Error querying cases: ' + e.getMessage());
            System.debug('Stack trace: ' + e.getStackTraceString());
            return new List<Case>();
        }
    }
    
    /**
     * Overloaded method to query cases by username instead of user ID
     * @param username The username of the user who created the cases
     * @return List of cases created by the specified user
     */
    public static List<Case> queryCasesByCreatedByUser(String username) {
        if (String.isBlank(username)) {
            System.debug('Error: username cannot be null or empty');
            return new List<Case>();
        }
        
        try {
            // First, find the user by username
            List<User> users = [
                SELECT Id, Name, Username 
                FROM User 
                WHERE Username = :username 
                LIMIT 1
            ];
            
            if (users.isEmpty()) {
                System.debug('No user found with username: ' + username);
                return new List<Case>();
            }
            
            User foundUser = users[0];
            System.debug('Found user: ' + foundUser.Name + ' (ID: ' + foundUser.Id + ')');
            
            // Call the main method with the user ID
            return queryCasesByCreatedByUser(foundUser.Id);
            
        } catch (Exception e) {
            System.debug('Error finding user by username: ' + e.getMessage());
            return new List<Case>();
        }
    }
    
    /**
     * Method to get current user's cases
     * @return List of cases created by the current running user
     */
    public static List<Case> queryCurrentUserCases() {
        return queryCasesByCreatedByUser(UserInfo.getUserId());
    }
}