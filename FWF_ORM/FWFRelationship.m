//
//  FWF
//
//  Created by Enrico Opri.
//  Copyright (c) 2013 Enrico Opri. All rights reserved.
//

#import "FWFRelationship.h"

#import "ClassUtility.h"
#import "commonClassExtensions.h"
#import "newOBJDataTypes.h"
#import "FWF_Costants.h"
#import "FWFORMDbWrapper.h"
#import "FWFEntity.h"
#import "FWF_Utils.h"


@implementation FWFRelationship
@synthesize referencedEntityClass = _referencedEntityClass;

-(id)initWithClass:(Class)cl{
    if (self = [super init]){
        if(![cl isSubclassOfClass:[FWFEntity class]])
            @throw(FWF_EXCEPTION_REFERENCED_CLASS_NOT_COMPLIANT);
        _referencedEntityClass = cl;
    }
        
    return self;
}

- (NSString *) referencedEntityName{
    return NSStringFromClass(_referencedEntityClass);
}
@end
