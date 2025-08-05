@isTest
public class CaseQueryHelperTest {
    
    @TestSetup
    static void setupTestData() {
        // Create test user
        Profile p = [SELECT Id FROM Profile WHERE Name='Standard User' LIMIT 1];
        User testUser = new User(
            Alias = 'tuser',
            Email = 'testuser@example.com',
            EmailEncodingKey = 'UTF-8',
            LastName = 'TestUser',
            LanguageLocaleKey = 'en_US',
            LocaleSidKey = 'en_US',
            ProfileId = p.Id,
            TimeZoneSidKey = 'America/Los_Angeles',
            UserName = 'testuser@example.com.test'
        );
        insert testUser;
        
        // Create test cases
        System.runAs(testUser) {
            List<Case> testCases = new List<Case>();
            
            testCases.add(new Case(
                Subject = 'Test Case 1 - Login Issue',
                Description = 'User cannot login to the system. Getting authentication error.',
                Status = 'New',
                Origin = 'Web'
            ));
            
            testCases.add(new Case(
                Subject = 'Test Case 2 - Performance Problem',
                Description = 'Application is running slowly during peak hours.',
                Status = 'In Progress',
                Origin = 'Email'
            ));
            
            testCases.add(new Case(
                Subject = 'Test Case 3 - Feature Request',
                Description = 'Request for new reporting functionality.',
                Status = 'New',
                Origin = 'Phone'
            ));
            
            insert testCases;
        }
    }
    
    @isTest
    static void testQueryCasesByCreatedByUserId() {
        // Get the test user
        User testUser = [SELECT Id FROM User WHERE UserName = 'testuser@example.com.test' LIMIT 1];
        
        Test.startTest();
        
        // Test the method with valid user ID
        List<Case> results = CaseQueryHelper.queryCasesByCreatedByUser(testUser.Id);
        
        Test.stopTest();
        
        // Verify results
        System.assertEquals(3, results.size(), 'Should return 3 test cases');
        
        // Verify that all cases belong to the test user
        for (Case c : results) {
            System.assertEquals(testUser.Id, c.CreatedById, 'Case should be created by test user');
            System.assertNotEquals(null, c.Subject, 'Subject should not be null');
        }
    }
    
    @isTest
    static void testQueryCasesByCreatedByUsername() {
        Test.startTest();
        
        // Test the method with valid username
        List<Case> results = CaseQueryHelper.queryCasesByCreatedByUser('testuser@example.com.test');
        
        Test.stopTest();
        
        // Verify results
        System.assertEquals(3, results.size(), 'Should return 3 test cases');
    }
    
    @isTest
    static void testQueryCurrentUserCases() {
        // Get the test user
        User testUser = [SELECT Id FROM User WHERE UserName = 'testuser@example.com.test' LIMIT 1];
        
        System.runAs(testUser) {
            Test.startTest();
            
            // Test the method for current user
            List<Case> results = CaseQueryHelper.queryCurrentUserCases();
            
            Test.stopTest();
            
            // Verify results
            System.assertEquals(3, results.size(), 'Should return 3 test cases for current user');
        }
    }
    
    @isTest
    static void testQueryCasesWithNullUserId() {
        Test.startTest();
        
        // Test with null user ID
        List<Case> results = CaseQueryHelper.queryCasesByCreatedByUser((Id)null);
        
        Test.stopTest();
        
        // Should return empty list
        System.assertEquals(0, results.size(), 'Should return empty list for null user ID');
    }
    
    @isTest
    static void testQueryCasesWithInvalidUsername() {
        Test.startTest();
        
        // Test with invalid username
        List<Case> results = CaseQueryHelper.queryCasesByCreatedByUser('invaliduser@example.com');
        
        Test.stopTest();
        
        // Should return empty list
        System.assertEquals(0, results.size(), 'Should return empty list for invalid username');
    }
}