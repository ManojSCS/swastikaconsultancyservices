# Swastika Consultancy Services Website

A professional website for accounting, bookkeeping, registration, and compliance services.

## Features

### Frontend
- **Responsive Design**: Mobile-friendly interface
- **Home Page**: Hero section with service overview
- **Services Section**: Display of all services offered
- **Packages Section**: Service pricing and packages
- **Shopping Cart**: Add packages to cart
- **User Authentication**: Login and registration
- **User Dashboard**: View subscriptions, orders, and payments
- **Admin Dashboard**: Manage users, orders, services, and payments

### Backend
- User registration and authentication
- Order management system
- Payment processing integration ready
- Database management

## Tech Stack

### Frontend
- HTML5
- CSS3
- JavaScript (Vanilla)

### Backend
- C++ (Server application)
- HTTP API endpoints

## Project Structure

```
swastika-consultancy/
├── index.html              # Main homepage
├── login.html              # User login page
├── register.html           # User registration
├── dashboard.html          # User dashboard
├── admin.html              # Admin panel
├── css/
│   ├── style.css          # Main styles
│   ├── auth.css           # Authentication styles
│   ├── admin.css          # Admin panel styles
│   └── dashboard.css      # Dashboard styles
├── js/
│   ├── script.js          # Main script
│   ├── auth.js            # Authentication logic
│   ├── admin.js           # Admin functionality
│   └── dashboard.js       # Dashboard functionality
├── backend/
│   └── server.cpp         # C++ backend server
└── README.md
```

## Getting Started

### Frontend
1. Open `index.html` in your web browser
2. Navigate through the site
3. Create an account or login
4. Browse and add services to cart

### Backend Setup

1. Compile the C++ backend:
   ```bash
   cd backend
   g++ -std=c++11 -o server server.cpp
   ./server
   ```

2. For a production backend, consider using:
   - Drogon Web Framework
   - Beast HTTP Library
   - cpp-httplib

## User Roles

### User Account
- View available services and packages
- Create orders
- Track order status
- View payment history
- Manage profile

### Admin Account
- Manage users
- View and manage orders
- Manage services and packages
- View payment transactions
- Generate reports

## Features Coming Soon

- Payment gateway integration (Razorpay, PayPal)
- Email notifications
- Advanced analytics
- Mobile app
- Real-time chat support
- Invoice generation

## Database Setup

The current implementation uses in-memory storage. For production, implement:
- MySQL/PostgreSQL
- MongoDB
- Firebase

## Security Considerations

1. **Password Hashing**: Use bcrypt or similar
2. **SSL/TLS**: Enable HTTPS
3. **Input Validation**: Sanitize all inputs
4. **CSRF Protection**: Implement token-based protection
5. **Rate Limiting**: Prevent brute force attacks
6. **SQL Injection Prevention**: Use prepared statements

## Deployment

### Frontend
- GitHub Pages
- Netlify
- Vercel
- AWS S3 + CloudFront

### Backend
- AWS EC2
- Heroku
- DigitalOcean
- Google Cloud

## Contact & Support

**Email**: info@swastikaconsultancy.com
**Phone**: +91-XXXX-XXXX-XX
**Website**: https://swastikaconsultancyservices.com/

## License

Copyright © 2024 Swastika Consultancy Services. All rights reserved.

## Contributing

Contributions are welcome! Please follow the contributing guidelines.

## Changelog

### v1.0.0 (Initial Release)
- Basic website structure
- User authentication system
- Service packages display
- Admin dashboard
- Backend server foundation
