BEGIN TRANSACTION;

-- Delete the row where AuditID is 'AU008'
DELETE FROM MsAudit
WHERE AuditID = 'AU008';

-- Commit the changes
COMMIT;

SELECT 
    AuditID,
    TableName,
    OperationID,
    CONCAT(UPPER(SUBSTRING(User, 1, 1)), LOWER(SUBSTRING(User, 2, LEN(User)))) AS User,
    Timestamp
FROM MsAudit;

SELECT 
    TransactionID,
    TransactionCategoryID,
    CONCAT('Made 1 transaction for ', ROUND(Amount, 0), ' ', LOWER(CurrencyID), ' at exactly ', Timestamp) AS TransactionMessage
FROM MsTransaction;