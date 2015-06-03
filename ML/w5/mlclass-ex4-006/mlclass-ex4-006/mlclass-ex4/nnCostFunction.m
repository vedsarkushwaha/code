function [J grad] = nnCostFunction(nn_params, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, ...
                                   X, y, lambda)
%NNCOSTFUNCTION Implements the neural network cost function for a two layer
%neural network which performs classification
%   [J grad] = NNCOSTFUNCTON(nn_params, hidden_layer_size, num_labels, ...
%   X, y, lambda) computes the cost and gradient of the neural network. The
%   parameters for the neural network are "unrolled" into the vector
%   nn_params and need to be converted back into the weight matrices.
% 
%   The returned parameter grad should be a "unrolled" vector of the
%   partial derivatives of the neural network.
%

% Reshape nn_params back into the parameters Theta1 and Theta2, the weight matrices
% for our 2 layer neural network
Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                 num_labels, (hidden_layer_size + 1));
%Theta1(:,1)
%Theta2(:,1)
% Setup some useful variables
m = size(X, 1);
         
% You need to return the following variables correctly 
J = 0;

Theta1_grad = zeros(size(Theta1));
Theta2_grad = zeros(size(Theta2));

% ====================== YOUR CODE HERE ======================
% Instructions: You should complete the code by working through the
%               following parts.
%
% Part 1: Feedforward the neural network and return the cost in the
%         variable J. After implementing Part 1, you can verify that your
%         cost function computation is correct by verifying the cost
%         computed in ex4.m

X=[ones(m,1),X];
a2=sigmoid(Theta1*X');
a2=[ones(1,m);a2];
a3=sigmoid(Theta2*a2);
yy=zeros(size(a3,1),size(a3,2));
for i=1:m
	yy(y(i),i)=1;
end
tmp_theta1=Theta1(:,2:size(Theta1,2));
tmp_theta2=Theta2(:,2:size(Theta2,2));

J=sum(sum((-yy.*log(a3))-((1-yy).*log(1-a3))))/m + (sum(sum(tmp_theta1.^2))+sum(sum(tmp_theta2.^2)))*(lambda/(2*m));

%
% Part 2: Implement the backpropagation algorithm to compute the gradients
%         Theta1_grad and Theta2_grad. You should return the partial derivatives of
%         the cost function with respect to Theta1 and Theta2 in Theta1_grad and
%         Theta2_grad, respectively. After implementing Part 2, you can check
%         that your implementation is correct by running checkNNGradients
%
%         Note: The vector y passed into the function is a vector of labels
%               containing values from 1..K. You need to map this vector into a 
%               binary vector of 1's and 0's to be used with the neural network
%               cost function.
%
%         Hint: We recommend implementing backpropagation using a for-loop
%               over the training examples if you are implementing it for the 
%               first time.

d3 = a3-yy;
d2 = (((Theta2')(2:end,:))*d3).*sigmoidGradient(Theta1*X');
#size(Theta2'*d3)
#size(Theta1*X')
#size(Theta1)
#size(X')
bd2 = d3*a2'(:,2:end);
%size(d2)
%size(X)
bd1 = d2*X(:,2:end);
%size(bd1,1)
%size(bd2,1)
Theta1_grad = [ones(size(bd1,1),1),bd1]/m;
Theta2_grad = [ones(size(bd2,1),1),bd2]/m;

%size(Theta1)
%size(Theta2)
%size(Theta1_grad)
%size(Theta2_grad)

%
% Part 3: Implement regularization with the cost function and gradients.
%
%         Hint: You can implement this around the code for
%               backpropagation. That is, you can compute the gradients for
%               the regularization separately and then add them to Theta1_grad
%               and Theta2_grad from Part 2.
%



















% -------------------------------------------------------------

% =========================================================================

% Unroll gradients
grad = [Theta1_grad(:) ; Theta2_grad(:)];


end
