/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou(at)doubango.org>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/

/**@file ProxyConsumer.h
 * @brief Audio/Video proxy consumers.
 *
 * @author Mamadou Diop <diopmamadou(at)doubango.org>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#ifndef TINYWRAP_CONSUMER_PROXY_H
#define TINYWRAP_CONSUMER_PROXY_H

#include "tinyWRAP_config.h"

class ProxyAudioConsumer
{
public:
	ProxyAudioConsumer();
	virtual ~ProxyAudioConsumer();

	/* Callback functions */
	virtual int prepare(int ptime, int rate, int channels) { return 0; }
	virtual int start() { return 0; }
	virtual int pause() { return 0; }
	virtual int stop() { return 0; }

	void setActivate(bool enabled);
	unsigned pull(void* output, unsigned size);

public:
	static bool registerPlugin();

#if !defined(SWIG)
	void takeConsumer(struct twrap_consumer_proxy_audio_s*);
	void releaseConsumer(struct twrap_consumer_proxy_audio_s*);
	static ProxyAudioConsumer* instance;
#endif

private:
	struct twrap_consumer_proxy_audio_s* consumer;
};




#endif /* TINYWRAP_CONSUMER_PROXY_H */