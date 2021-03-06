//
//  FWF
//
//  Created by Enrico Opri.
//  Copyright (c) 2013 Enrico Opri. All rights reserved.
//

#pragma GCC diagnostic ignored "-Wobjc-autosynthesis-property-ivar-name-match"

#import <Foundation/Foundation.h>

#import "commonClassExtensions.h"

#import "FWFORMDbWrapper.h"

@class FWFList;

@protocol FWFRELATIONSHIPSupport

@optional
- (void) initForeignKeys;

@end

@interface FWFEntity : NSObject <FWFRELATIONSHIPSupport> {
    BOOL __deleted;
}

@property (assign, nonatomic) BOOL __deleted;

/*
 * INITIALIZERS
 */

//init entity without persistence check
-(id) init;
//init entity checking persistence (create needed table if they are not already present in the Database)
-(id) initWithPersistenceCheck;
//init persistence only (does not return an object). Advice: call this method at startup, before any other call to the objects
-(void) initEntityPersistence;

- (NSString *) entityName;
+ (NSString *) entityName;

- (NSUInteger) pk;
- (OBJUInteger *) pkOBJ;

- (void) save;

- (void) setValuesForAttributesWithDictionary:(NSDictionary *)keyedValues;
- (NSDictionary *) getAttributesValues;
- (NSDictionary *) getAllAttributesValues;

+ (FWFList *) objects;

- (bool) deleteWithDbObj:(FWFORMDbWrapper *)database;
- (void) deleteFromStorage;

- (NSDictionary *) getValuesDictionary;
- (NSDictionary *) serializeWithDictionary;

/**************/
/*  SETTINGS  */
/**************/

//allowing to save null objects is setted to false as default, override to modify this
- (bool) isNullEntityNotAllowed;


@end
