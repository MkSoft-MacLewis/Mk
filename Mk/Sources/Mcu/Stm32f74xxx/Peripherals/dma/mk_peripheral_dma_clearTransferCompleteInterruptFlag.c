/**
*
* @copyright Copyright (C) 2018 RENARD Mathieu. All rights reserved.
*
* This file is part of Mk.
*
* Mk is free software. Redistribution and use in source and binary forms, with or
* without modification, are permitted provided that the following conditions are
* met:
*
*    1. Redistributions of source code must retain the above copyright notice,
*       this list of conditions and the following disclaimer.
*    2. Redistributions in binary form must reproduce the above copyright notice,
*       this list of conditions and the following disclaimer in the documentation
*       and/or other materials provided with the distribution.
*    3. Neither the name of the copyright holder nor the names of its contributors
*       may be used to endorse or promote products derived from this software
*       without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
* ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* @file mk_peripheral_dma_clearTransferCompleteInterruptFlag.c
* @brief Définition de la fonction dma_clearTransferCompleteInterruptFlag.
* @date 27 oct. 2018
*
*/

#include "mk_peripheral_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void dma_clearTransferCompleteInterruptFlag ( void_t p_addr, uint32_t p_stream )
{
   /* Si le drapeau d'interruption du flux numéro 0 doit être remis à zéro */
   if ( p_stream == K_DMA_STREAM0 )
   {
      /* Remise à zéro du drapeau d'interruption */
      _or ( ( addr_t ) p_addr + 2, 0x00000020 );
   }

   /* Sinon si le drapeau d'interruption du flux numéro 1 doit être remis à zéro */
   else if ( p_stream == K_DMA_STREAM1 )
   {
      /* Remise à zéro du drapeau d'interruption */
      _or ( ( addr_t ) p_addr + 2, 0x00000800 );
   }

   /* Sinon si le drapeau d'interruption du flux numéro 2 doit être remis à zéro */
   else if ( p_stream == K_DMA_STREAM2 )
   {
      /* Remise à zéro du drapeau d'interruption */
      _or ( ( addr_t ) p_addr + 2, 0x00200000 );
   }

   /* Sinon si le drapeau d'interruption du flux numéro 3 doit être remis à zéro */
   else if ( p_stream == K_DMA_STREAM3 )
   {
      /* Remise à zéro du drapeau d'interruption */
      _or ( ( addr_t ) p_addr + 2, 0x08000000 );
   }

   /* Sinon si le drapeau d'interruption du flux numéro 4 doit être remis à zéro */
   else if ( p_stream == K_DMA_STREAM4 )
   {
      /* Remise à zéro du drapeau d'interruption */
      _or ( ( addr_t ) p_addr + 3, 0x00000020 );
   }

   /* Sinon si le drapeau d'interruption du flux numéro 5 doit être remis à zéro */
   else if ( p_stream == K_DMA_STREAM5 )
   {
      /* Remise à zéro du drapeau d'interruption */
      _or ( ( addr_t ) p_addr + 3, 0x00000800 );
   }

   /* Sinon si le drapeau d'interruption du flux numéro 6 doit être remis à zéro */
   else if ( p_stream == K_DMA_STREAM6 )
   {
      /* Remise à zéro du drapeau d'interruption */
      _or ( ( addr_t ) p_addr + 3, 0x00200000 );
   }

   /* Sinon si le drapeau d'interruption du flux numéro 7 doit être remis à zéro */
   else if ( p_stream == K_DMA_STREAM7 )
   {
      /* Remise à zéro du drapeau d'interruption */
      _or ( ( addr_t ) p_addr + 3, 0x08000000 );
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return;
}



