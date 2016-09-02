/*
 * Copyright (c) 2003-2004 Apple Computer, Inc. All Rights Reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

#ifndef _H_EVENTLISTENER
#define _H_EVENTLISTENER

#include <securityd_client/ssclient.h>
#include <security_utilities/cfmach++.h>


namespace Security {
namespace SecurityServer {


//
// A CFNotificationDispatcher registers with the local CFRunLoop to automatically
// receive notification messages and dispatch them.
//
class EventListener : private MachPlusPlus::CFAutoPort,
	protected SecurityServer::ClientSession::NotificationConsumer,
	private SecurityServer::ClientSession {
public:
	EventListener(NotificationDomain domain, NotificationMask eventMask,
		Allocator &standard = Allocator::standard(), Allocator &returning = Allocator::standard());
	virtual ~EventListener();

	// NotificationConsumer::consume (virtual from NotificationConsumer) is still abstract here

private:
	void receive(const MachPlusPlus::Message &message);
};


} // end namespace SecurityServer
} // end namespace Security


#endif
