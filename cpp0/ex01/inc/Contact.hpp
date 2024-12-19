/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:52:30 by dalebran          #+#    #+#             */
/*   Updated: 2024/12/19 03:54:25 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Contact
{
  private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::string truncateValue(std::string value) const;

  public:
	void setContact();
	void setFirstName();
	void setLastName();
	void setNickname();
	void setPhoneNumber();
	void setDarkestSecret();
	void displaySummary(int i) const;
	void displayFullInfo() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
};
